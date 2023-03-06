def CountSort(seq):
    count = [0,0,0]

    if len(seq) == 1:
        return seq, 0
    
    seq_low, count[0] = CountSort(seq[:len(seq)//2])
    seq_high, count[1] = CountSort(seq[len(seq)//2:])
    seq, count[2] = MergeCount(seq_low, seq_high)
    return seq, sum(count)
    
def MergeCount(seq_low, seq_high):
    count = 0
    seq = []
    while len(seq_low) and len(seq_high):
        if seq_low[0][1] <= seq_high[0][1]:
            seq.append(seq_low.pop(0))
        else:
            seq.append(seq_high.pop(0))
            count += len(seq_low)
        
    seq.extend(seq_low)
    seq.extend(seq_high)
    
    return seq, count

t = int(input())
for _ in range(t):
    size = int(input())

    seq = []
    for _ in range(size):
        seq.append([int(input()), 0])

    for i in range(size):
        seq[i][1] = int(input())

    seq = sorted(seq,key=lambda x: (x[0]))
    _, count = CountSort(seq)
    print(count)