#!/usr/bin/python3
"""
Parses a web server log file, every line should be in the following format:

- <IP Address> - [<date>] "<method> <resource-uri> <protocol>" <status code>
<file size>

Every 10 lines, the size of the read contents and the count for every found
status code will be printed to the standard output.
"""
import sys


def get_info_from_line(line, info):
    splitted = line.split()[::-1]
    if len(splitted) < 3:
        return False

    status = splitted[1]
    if status not in ("200", "301", "400", "401", "403", "404", "405", "500"):
        return

    filesize = splitted[0]

    if status in info["status"]:
        info["status"][status] += 1
    else:
        info["status"][status] = 1
    info["total_size"] += int(filesize)

    return True


if __name__ == "__main__":
    count = 0
    info = {
        "status": {},
        "total_size": 0
    }

    try:
        for line in sys.stdin:
            if get_info_from_line(line, info) == True:
                count += 1

            if count == 10:
                print("File size: {}".format(info["total_size"]))
                for key in sorted(info["status"]):
                    print("{}: {}".format(key, info["status"][key]))
                count = 0
    finally:
        print("File size: {}".format(info["total_size"]))
        for key in sorted(info["status"]):
            print("{}: {}".format(key, info["status"][key]))
