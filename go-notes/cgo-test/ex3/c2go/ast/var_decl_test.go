package ast

import (
	"testing"
)

func TestVarDecl(t *testing.T) {
	nodes := map[string]Node{
		`0x7fd5e90e5a00 <col:14> col:17 'int'`: &VarDecl{
			Addr:         0x7fd5e90e5a00,
			Pos:          NewPositionFromString("col:14"),
			Position2:    "col:17",
			Name:         "",
			Type:         "int",
			Type2:        "",
			IsExtern:     false,
			IsUsed:       false,
			IsNRVO:       false,
			IsCInit:      false,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   false,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x7fd5e90e9078 <line:156:1, col:14> col:14 __stdinp 'FILE *' extern`: &VarDecl{
			Addr:         0x7fd5e90e9078,
			Pos:          NewPositionFromString("line:156:1, col:14"),
			Position2:    "col:14",
			Name:         "__stdinp",
			Type:         "FILE *",
			Type2:        "",
			IsExtern:     true,
			IsUsed:       false,
			IsNRVO:       false,
			IsCInit:      false,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   false,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x7fd5e90ed630 <col:40, col:47> col:47 __size 'size_t':'unsigned long'`: &VarDecl{
			Addr:         0x7fd5e90ed630,
			Pos:          NewPositionFromString("col:40, col:47"),
			Position2:    "col:47",
			Name:         "__size",
			Type:         "size_t",
			Type2:        "unsigned long",
			IsExtern:     false,
			IsUsed:       false,
			IsNRVO:       false,
			IsCInit:      false,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   false,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x7fee35907a78 <col:4, col:8> col:8 used c 'int'`: &VarDecl{
			Addr:         0x7fee35907a78,
			Pos:          NewPositionFromString("col:4, col:8"),
			Position2:    "col:8",
			Name:         "c",
			Type:         "int",
			Type2:        "",
			IsExtern:     false,
			IsUsed:       true,
			IsNRVO:       false,
			IsCInit:      false,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   false,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x7fb0fd90ba30 <col:3, /usr/include/sys/_types.h:52:33> tests/assert/assert.c:13:9 used b 'int *' cinit`: &VarDecl{
			Addr:         0x7fb0fd90ba30,
			Pos:          NewPositionFromString("col:3, /usr/include/sys/_types.h:52:33"),
			Position2:    "tests/assert/assert.c:13:9",
			Name:         "b",
			Type:         "int *",
			Type2:        "",
			IsExtern:     false,
			IsUsed:       true,
			IsNRVO:       false,
			IsCInit:      true,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   false,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x7fb20308bd40 <col:5, col:11> col:11 referenced a 'short'`: &VarDecl{
			Addr:         0x7fb20308bd40,
			Pos:          NewPositionFromString("col:5, col:11"),
			Position2:    "col:11",
			Name:         "a",
			Type:         "short",
			Type2:        "",
			IsExtern:     false,
			IsUsed:       false,
			IsNRVO:       false,
			IsCInit:      false,
			IsReferenced: true,
			IsStatic:     false,
			IsRegister:   false,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x55a040ddd798 <sqlite3.c:66:1, line:770:1> line:66:27 used sqlite3azCompileOpt 'const char *const [2]' static cinit`: &VarDecl{
			Addr:         0x55a040ddd798,
			Pos:          NewPositionFromString("sqlite3.c:66:1, line:770:1"),
			Position2:    "line:66:27",
			Name:         "sqlite3azCompileOpt",
			Type:         "const char *const [2]",
			Type2:        "",
			IsExtern:     false,
			IsUsed:       true,
			IsNRVO:       false,
			IsCInit:      true,
			IsReferenced: false,
			IsStatic:     true,
			IsRegister:   false,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x55772c7774d0 <col:3, col:27> col:27 used a 'unsigned char *' register`: &VarDecl{
			Addr:         0x55772c7774d0,
			Pos:          NewPositionFromString("col:3, col:27"),
			Position2:    "col:27",
			Name:         "a",
			Type:         "unsigned char *",
			Type2:        "",
			IsExtern:     false,
			IsUsed:       true,
			IsNRVO:       false,
			IsCInit:      false,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   true,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x26fd180 <col:4, col:32> col:13 used aExt 'extCoord':'extCoord' cinit`: &VarDecl{
			Addr:         0x26fd180,
			Pos:          NewPositionFromString("col:4, col:32"),
			Position2:    "col:13",
			Name:         "aExt",
			Type:         "extCoord",
			Type2:        "extCoord",
			IsExtern:     false,
			IsUsed:       true,
			IsNRVO:       false,
			IsCInit:      true,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   false,
			Parent:       0,
			ChildNodes:   []Node{},
		},
		`0x7f985e0ffb10 parent 0x7f985e0246d0 <col:3, col:20> col:20 used DEFAULT_MEM_ALLOCATOR 'cmark_mem':'struct cmark_mem' extern`: &VarDecl{
			Addr:         0x7f985e0ffb10,
			Pos:          NewPositionFromString("col:3, col:20"),
			Position2:    "col:20",
			Name:         "DEFAULT_MEM_ALLOCATOR",
			Type:         "cmark_mem",
			Type2:        "struct cmark_mem",
			IsExtern:     true,
			IsUsed:       true,
			IsNRVO:       false,
			IsCInit:      false,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   false,
			Parent:       0x7f985e0246d0,
			ChildNodes:   []Node{},
		},
		`0x55d681e87428 <col:5, col:23> col:23 used variable 'union programming':'union programming' nrvo`: &VarDecl{
			Addr:         0x55d681e87428,
			Pos:          NewPositionFromString("col:5, col:23"),
			Position2:    "col:23",
			Name:         "variable",
			Type:         "union programming",
			Type2:        "union programming",
			IsExtern:     false,
			IsUsed:       true,
			IsNRVO:       true,
			IsCInit:      false,
			IsReferenced: false,
			IsStatic:     false,
			IsRegister:   false,
			ChildNodes:   []Node{},
		},
	}

	runNodeTests(t, nodes)
}