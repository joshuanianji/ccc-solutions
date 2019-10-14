import os
import re
import collections

fnamere = re.compile(r'(\d{2})(j|s)(\d)\.(py|cpp)')

sols = collections.defaultdict()
Solution = collections.namedtuple('Solution', ['year', 'pnum', 'ftype'])

for f in os.listdir('solutions'):
    year, ptype, pnum, ftype = fnamere.match(f).groups()

    year = int(year)
    pnum = int(pnum)

    # senior problems only
    assert ptype == 's'

    sols[(year, pnum)] = Solution(year, pnum, ftype)

res = ["<table><tr><th>Year</th>"]

for i in range(1, 6):
    res.append(f"<th>{i}</th>")

res.append("</tr>")

prevyr = -1
for year in range(19, 0, -1):
    tmp = []
    changed = False
    tmp.append(f"<tr><td>{year}</td>")
    for p in range(1, 6):
        if (year, p) in sols:
            s = sols[(year, p)]
            tmp.append(f"<td>[{s.ftype.upper()}](solutions/{s.year}s{s.pnum}.{s.ftype})</td>")
            changed = True
        else:
            tmp.append('<td></td>')
    if changed:
        res.extend(tmp)

with open('README.md', 'w') as fh, open('readme_header.txt') as hdr:
    fh.write(hdr.read())
    fh.write(''.join(res))