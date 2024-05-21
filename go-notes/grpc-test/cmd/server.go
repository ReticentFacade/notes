package cmd

import (
	"context"
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net"
	"net/http"
	"strings"

	pb "github.com/ReticentFacade/go-notes/grpc-test/pkg/gopher"
	"github.com/spf13/cobra"
	"golang.org/x/xerrors"
	"google.golang.org/grpc"
)

const (
	port         = ":9000"
	KuteGoAPIURL = "https://kutego-api-xxxxx-ew.a.run.app"
)

// server needs to implement gopher.GopherServer
type Server struct {
	pb.UnimplementedGopherServer
}
type Gopher struct {
	URL string `json:"url"`
}

// serverCmd represents the server command
var serverCmd = &cobra.Command{
	Use:   "server",
	Short: "Sets up Gopher server",
	Long:  `Gopher server written in Golang`,
	Run: func(_ *cobra.Command, _ []string) {
		fmt.Println("server called...")
		lis, err := net.Listen("tcp", port)
		if err != nil {
			log.Fatalln("failed to listen: %w", err)
		}

		grpcServer := grpc.NewServer()

		// Register new services:
		pb.RegisterGopherServer(grpcServer, &Server{})
		log.Printf("gRPC server listening on: %v", lis.Addr())

		if err := grpcServer.Serve(lis); err != nil {
			log.Fatal("failed to serve:%w", err)
		}
	},
}

func (s *Server) GetGopher(ctx context.Context, req *pb.GopherRequest) (*pb.GopherReply, error) {
	res := &pb.GopherReply{}

	// Check request
	if req == nil {
		fmt.Println("request must not be nil")
		return res, xerrors.Errorf("request must not be nil")
	}

	if req.Name == "" {
		fmt.Println("name must not be empty in the request")
		return res, xerrors.Errorf("name must not be empty in the request")
	}

	log.Printf("Received: %v", req.GetName())

	// Call KuteGo API in order to get Gopher's URL
	response, err := http.Get(KuteGoAPIURL + "/gophers?name=" + req.GetName())
	if err != nil {
		log.Fatalf("failed to call KuteGoAPI: %v", err)
	}
	defer response.Body.Close()

	if response.StatusCode == 200 {
		// Transform our response to a []byte
		body, err := io.ReadAll(response.Body)
		if err != nil {
			log.Fatalf("failed to read response body: %v", err)
		}

		// Put only needed details of the JSON document in our array of Gopher
		var data []Gopher
		err = json.Unmarshal(body, &data)
		if err != nil {
			log.Fatalf("failed to unmarshal JSON: %v", err)
		}

		// Create a string with all of the Gopher's name and a blank line as separator
		var gophers strings.Builder
		for _, gopher := range data {
			gophers.WriteString(gopher.URL + "\n")
		}

		res.Message = gophers.String()
	} else {
		log.Fatal("Can't get the Gopher :-(")
	}

	return res, nil
}
func init() {
	rootCmd.AddCommand(serverCmd)
}
