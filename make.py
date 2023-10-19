import os
import sys
import argparse

# get attribute
parser = argparse.ArgumentParser()
parser.add_argument('--num', type=str, default='0')
parser.add_argument('--name', type=str, default='default')


args = parser.parse_args()

if not os.path.exists(f"./{args.num}_{args.name}"):
    os.makedirs(f"./{args.num}_{args.name}")

# make file
with open(f"./{args.num}_{args.name}/solve.py", "w") as f:
    f.write("import sys\n\n")
    f.write("readl = sys.stdin.readline\n")
    f.close()

with open(f"./{args.num}_{args.name}/q.md", "w") as f:
    f.write("# Question\n")
    f.write(f"[link](https://www.acmicpc.net/problem/{args.num})\n")
    f.close()
