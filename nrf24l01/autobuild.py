#!/usr/bin/env python3

import sys
import time
import subprocess
import termcolor

from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
from subprocess import Popen


class WatchMeHandler(FileSystemEventHandler):
    __lastEvent = 0
    __blockTime = 3

    def on_modified(self, event):
        if self.__lastEvent + self.__blockTime > time.time():
            return

        self.__lastEvent = time.time()

        process = subprocess.run(['make'])

        if process.returncode != 0:
            print(termcolor.colored(">>> ERROR", 'red'))
        else:
            print(termcolor.colored(">>> OK", 'green'))


def main():
    foldersToWatch = ['./src', '../libs/xXx']

    observer = Observer()

    for folder in foldersToWatch:
        observer.schedule(WatchMeHandler(), folder, recursive=True)

    observer.start()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()

    observer.join()

if __name__ == '__main__':
    main()
