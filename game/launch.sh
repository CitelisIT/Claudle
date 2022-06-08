#!/bin/bash

trap 'wait' EXIT
trap 'kill 0' SIGINT

activate () {
source ./env/bin/activate
}

activate

nohup python3 server.py &

npm start --prefix frontend

