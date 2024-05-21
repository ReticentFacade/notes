# Containerisation: 

## `Dockerfile` 
- A file that contains details such as: 
  * The operating system 
  * Steps to run the project on that OS 
  * Dependencies of the project 

- A `Dockerfile` makes the installation of auxiliary services [for eg: Kafka, MongoDB, or other databases] easy.

## Format for `Dockerfile`

```
FROM node:20                 -------> whatever node-version you're using
WORKDIR /usr/src/app         -------> the directory you want the stuff to be copied TO
COPY . .                     -------> "Copy everything from this directory to the one mentioned above"
RUN npm install              -------> Install all dependencies
EXPOSE 3000                  -------> Which port the file would run on 
CMD ["node", "index.js"]     -------> The (final) command to run when the container is actually running ( = Before the image gets converted into a container)
```

## How should a Dockerfile be structured: [= LAYER CACHING]

Since each steps acts as a layer in itself, you'd want to install the `Dependencies` first, and then follow up with the commands and _then_ with the files of the project.

So, the structure should be something like this: 
```
From mhart/alpine-node

WORKDIR /usr/src/app

COPY package.*               --------> This step is where you're copying the files that contain listed dependencies BEFORE doing anything else

RUN npm install              --------> Now, installing the dependencies

COPY . . 
```
