#!/usr/bin/env python2

import sys
from matplotlib import pyplot as plt

def parselog(logfile, with_challenge, graph_output):
    data={}
    for line in logfile:
        if line.startswith("P2PSIPTestApp:"):
            tokens = line.split()
            msgtype, success, timestamp = tokens[1], tokens[2], tokens[3]
            print msgtype, success, timestamp
            timestampnum = float(timestamp[3:-1])
            data.setdefault((msgtype,success),[]).append(timestampnum)
        elif line.startswith("[Chord::READY]"):
            tokens = line.split()
            ipaddress, ts = tokens[1], tokens[2]
            data.setdefault(('Chord','ready'),[]).append(float(ts))

    if with_challenge:
        props = {
            ('Register', 'success'): '^g',
            ('Register', 'failed'): '^r',
            ('Resolve', 'failed'): 'or',
            ('Challenge', 'success'): 'og',
            ('Challenge', 'failed'): 'oy',
            ('Chord', 'ready'): '+b'
        }
    else:
        props = {
            ('Register', 'success'): '^g',
            ('Register', 'failed'): '^r',
            ('Resolve', 'failed'): 'or',
            ('Resolve', 'success'): 'og',
            ('Chord', 'ready'): '+b'
        }

    for k in data:
        cumulx = []
        cumuly = []
        cval =0
        for t in data[k]:
            cval+=1
            cumulx.append(t)
            cumuly.append(cval)
        if k in props:
            plt.plot(cumulx, cumuly, props[k])

    plt.savefig(graph_output, bbox_inches='tight')

if __name__ == '__main__':
    with_challenge = sys.argv[1].lower() in ('true', 'yes', '1')
    if len(sys.argv) > 3:
        with open(sys.argv[3]) as logfile:
            parselog(logfile, with_challenge, sys.argv[2])
    else:
        parselog(sys.stdin, with_challenge, sys.argv[2])
