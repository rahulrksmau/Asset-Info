# Make file writing 
# main, application, cpu_info, disk, ip, it-asset, files
# Specify what I need in the end. One single executable
main : main.o

# but how that will proceed from where *.o will come

	g++ -std=c++11 -o main *.cpp

#-----------------------------------------------------------------

# Now where is *.o files are , hmmm.. lets create it
main.o : *.cpp  *.h
	g++ -std=c++11 -c *.cpp


