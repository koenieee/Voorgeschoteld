#!/usr/bin/env python2
import gzip
from cStringIO import StringIO
import zmq
import time
from datetime import datetime
import os
context = zmq.Context()
subscriber = context.socket(zmq.XSUB)
subscriber.connect("tcp://pubsub.besteffort.ndovloket.nl:7658")
subscriber.send(chr(0x01) + "/SYNTUS/KV6posinfo") # 0x01 = subscribe, 0x00 = unsubscribe
counter = 0

data = ''
print "ZEROMQ - API TEST NDOVLOKET"

while True:
	try:
		multipart = subscriber.recv_multipart()
		address = multipart[0]
		print address
		contents = ''.join(multipart[1:])
		contents = gzip.GzipFile('','r',0,StringIO(contents)).read()
		#print contents
	except: print("FAILURE")