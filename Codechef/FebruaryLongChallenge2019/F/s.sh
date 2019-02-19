mkfifo fifo
python3 pycode.py < fifo | python3 comm_code.py > fifo
