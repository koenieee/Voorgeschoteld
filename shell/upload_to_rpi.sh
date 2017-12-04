#!/bin/bash
cd ../
scp Voorgeschoteld pi@192.168.178.79:/home/pi
ssh pi@192.168.178.79 "sh -c '/home/pi/Voorgeschoteld'"