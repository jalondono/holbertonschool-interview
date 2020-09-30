import signal
import sys
import time

def main_function():

    data_for_signal_handler = 10

    def signal_handler(*args):
        print (data_for_signal_handler)
        sys.exit()

    signal.signal(signal.SIGINT, signal_handler) # Or whatever signal

    while True:
        data_for_signal_handler += 1
        time.sleep(0.5)

if __name__ == '__main__':
    main_function()