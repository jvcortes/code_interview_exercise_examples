#!/usr/bin/python3
"""
Parses a web server log file, every line should be in the following format:

- <IP Address> - [<date>] "<method> <resource-uri> <protocol>" <status code>
<file size>

Every 10 lines, the size of the read contents and the count for every found
status code will be printed to the standard output.
"""
import re
import signal
import sys


def parse():
    count = 0
    parse.info = {
        "status": {},
        "total_size": 0
    }

    while True:
        line = input()
        count += 1
        get_info_from_line(line, parse.info)

        if count == 9:
            print_info(parse.info)
            count = 0


def get_info_from_line(line, info):
    status = re.search(r"\".*\"\W([0-9]*).*$", line).group(1)
    filesize = re.search(r"\".*\"\W[0-9]*\W([0-9]*)$", line).group(1)
    if status in info["status"]:
        info["status"][status] += 1
    else:
        info["status"][status] = 1
    info["total_size"] += int(filesize)


def print_info(info):
    print("File size: {}".format(info["total_size"]))
    for key in sorted(info["status"]):
        print("{}: {}".format(key, info["status"][key]))


def handle_sigint(signal, frame):
    print_info(parse.info)
    exit(0)


if __name__ == "__main__":
    signal.signal(signal.SIGINT, handle_sigint)
    parse()
