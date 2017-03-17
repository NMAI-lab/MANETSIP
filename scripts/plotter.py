#!/usr/bin/env python2

import sys
from matplotlib import pyplot as plt

def plot_simtime():
    plt.plot([25,37,40,50,62,75,100],[471,1157,960,1657,3214,5752,10520],'o')
    plt.xlabel('number of nodes')
    plt.ylabel('simulation time (s)')

    plt.yticks([0,600,1800,3600,7200,10800],['0', '10 min', '30 min','1 h', '2 h', '3 h'])
    plt.title('simulation time: 10 min')

    plt.show()

def parselog(logfile, processed):
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

    shape={'Register': '^', 'Resolve':'o', 'Chord':'+'}
    col={'Success':'g', 'success':'g', 'failed':'r', 'ready':'b'}
    for k in data:
        cumulx = []
        cumuly = []
        cval =0
        processed.write(str(k)+":\t")
        for t in data[k]:
            cval+=1
            cumulx.append(t)
            cumuly.append(cval)
            processed.write(str((t,cval))+"\t")
        plt.plot(cumulx,cumuly, shape[k[0]]+col[k[1]])
        processed.write("\n")

    plt.show()


if __name__ == '__main__':
    if len(sys.argv) > 1:
        with open(sys.argv[1]) as logfile:
            with open(sys.argv[1] + '.ppp', 'w') as processed:
                parselog(logfile, processed)
    else:
        with open('processed.log', 'w') as processed:
            parselog(sys.stdin, processed)
