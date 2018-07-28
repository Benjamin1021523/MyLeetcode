# Read from the file file.txt and output the tenth line to stdout.
line_cnt=$(cat file.txt | wc -l) #變數賦值時不可以加$號，那是取值用的，另外=左右也不能空格
if [ $line_cnt -ge 10 ]; then
    cat file.txt | head -n 10 | tail -n 1 #印出前10行再印出最後一行
fi

#參考自https://blog.csdn.net/sole_cc/article/details/44977821
#我要學的東西還很多
#對我來說，shell script就是一連串靠創意組合小工具完成工作的挑戰