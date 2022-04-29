#!/bin/bash

nohup python3 server.py &

npm start --prefix frontend/

kill $!
