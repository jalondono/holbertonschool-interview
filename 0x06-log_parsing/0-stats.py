#!/usr/bin/python3
"""Log parsing"""
import sys
import signal


def main():
    count = 0
    data = {}
    size = 0

    def signal_handler(*args):
        print("File size: {}".format(size))
        for key, value in data.items():
            if data[key] != 0:
                print("{}: {}".format(key, value))
        sys.exit()

    signal.signal(signal.SIGINT, signal_handler)

    for line in sys.stdin:
        response = line.split(' ')[-2:]
        status = response[0]
        size += int(response[1][:-1])

        if status not in data:
            data[status] = 1
        else:
            data[status] += 1

        if count >= 9:
            print("File size: {}".format(size))
            for key, value in data.items():
                if data[key] != 0:
                    print("{}: {}".format(key, value))
            count = 0
        count += 1


if __name__ == '__main__':
    main()
