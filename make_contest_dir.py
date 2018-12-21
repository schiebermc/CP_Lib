import argparse
import subprocess

if __name__ == "__main__":

    parser = argparse.ArgumentParser(
        description='Argument Parser for Adjusted Historical Prices')
    parser.add_argument("-n", "-name", type=str, default='BADNAME')
    parser.add_argument("-np", "-number_of_problems", type=int, default=5)

    args = parser.parse_args() 
    
    np = args.np
    name = args.n

    letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I']

    bashCommand = 'mkdir ' + name
    output = subprocess.check_output(['bash','-c', bashCommand])

    for ind, val in enumerate(letters[:np]):

        dirname = name + '/' + val
        bashCommand = 'mkdir ' + dirname
        output = subprocess.check_output(['bash','-c', bashCommand])

        bashCommand = 'cp /Users/schiebermc/Gits/CP_Lib/main_template/* ' + dirname + '/'  
        output = subprocess.check_output(['bash','-c', bashCommand])


