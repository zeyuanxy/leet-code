#!/usr/bin/env python

import os
import urllib2
import time
import re
import shutil

def get_problem_id(url):
    print url
    response = urllib2.urlopen(url)   
    html = response.read()
    res = re.search('name="question_id" value="(\d+)"', html)
    return int(res.group(1))

if __name__ == "__main__":
    for problem in os.listdir('2014'):
        problem_id = get_problem_id('https://leetcode.com/problems/' + problem)
        problem_vol = 'vol1'
        if problem_id <= 50:
            problem_vol = 'vol1'            
        elif problem_id <= 100:
            problem_vol = 'vol2'
        elif problem_id <= 150:
            problem_vol = 'vol3'
        else:
            problem_vol = 'vol4'
        shutil.move('2014/' + problem, problem_vol)
        print 'move ' + problem + ' into ' + problem_vol
        time.sleep(1)
        
