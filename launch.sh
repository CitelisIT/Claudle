#!/bin/bash

trap 'wait' EXIT
trap 'kill 0' SIGINT

nohup python3 server.py &

npm start --prefix frontend/

