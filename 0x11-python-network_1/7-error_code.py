#!/usr/bin/python3

"""this will send a request to a given URL and displays the response body.
Usage: ./7-error_code.py <URL>
  - Handles HTTP errors.
"""

import sys
import requests


if __name__ == "__main__":
    url = sys.argv[1]

    req = requests.get(url)
    if req.status_code >= 400:
        print("Error code: {}".format(req.status_code))
    else:
        print(req.text)
