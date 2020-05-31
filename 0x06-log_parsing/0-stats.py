#!/usr/bin/python3
"""Log parsing"""
import sys
import signal


def main():
    count = 0
    data = {'200': 0, '301': 0, '400': 0, '401': 0,
            '403': 0, '404': 0, '405': 0, '500': 0}
    size = 0

    def signal_handler(*args):
        print("File size: {}".format(size))
        for key in sorted(data.keys()):
            if data[key] != 0:
                print("{}: {}".format(key, data[key]))
        sys.exit(0)

    signal.signal(signal.SIGINT, signal_handler)

    for line in sys.stdin:
        response = line.split(' ')[-2:]
        status = response[0]
        size += int(response[1][:-1])

        # if status not in data:
        #     data[status] = 1
        # else:
        #     data[status] += 1
        data[status] += 1

        if count >= 9:
            print("File size: {}".format(size))
            for key in sorted(data.keys()):
                if data[key] != 0:
                    print("{}: {}".format(key, data[key]))
            count = 0
        else:
            count += 1


if __name__ == '__main__':
    main()
