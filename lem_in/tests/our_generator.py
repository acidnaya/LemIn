#!/usr/bin/python
#usage python our_generator.py int_num_ants ~int_num_rooms ~int_num_links Bool_2be_visualized

import sys
from random import randint

def check_coordinates(new, oldlist):
	for old in oldlist:
		if ((old[0] - new[0])**2 + (old[1] - new[1])**2) ** 0.5 < 15:
			return False
	return True

def main(argv):
	print sys.argv[1]
	print "##start"
	print "start 0 0"
	print "##end"
	print "end 100 100"
	#rooms
	coordinates = []
	for i in range(int(sys.argv[2]) + 1):
		new_coord = [randint(5, 95), randint(5, 95)]
		if (sys.argv[4] == "1"):
			while (check_coordinates(new_coord, coordinates) == False):
				new_coord = [randint(5, 95), randint(5, 95)]
		coordinates.append(new_coord);
		print str(i) + " " + str(new_coord[0]) + " " + str(new_coord[1])
	#links
	for i in range(int(sys.argv[3])):
		room1 = randint(0, int(sys.argv[2]))
		room2 = randint(0, int(sys.argv[2]))
		while (room1 == room2):
			room2 = randint(0, int(sys.argv[2]))
		print str(room1) + "-" + str(room2)
	for i in range(int(sys.argv[3]) / 6):
		print "start-" + str(randint(0, int(sys.argv[2])))
	for i in range(int(sys.argv[3]) / 6):
		print "end-" + str(randint(0, int(sys.argv[2])))

if __name__ == "__main__":
	main(sys.argv)


