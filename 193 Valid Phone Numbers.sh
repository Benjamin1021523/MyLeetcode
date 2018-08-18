# Read from the file file.txt and output all valid phone numbers to stdout.
#grep -E "^([0-9]{3}-[0-9]{3}-[0-9]{4}|\([0-9]{3}\) [0-9]{3}-[0-9]{4})$" file.txt
grep -E "^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$" file.txt

# grep 參數 字串 目標檔案(們)
# -E 把字串內容展開成regex去比對
# 目標字串是(xxx) xxx-xxxx or xxx-xxx-xxxx

# 從   (xxx) xxx-xxxx或xxx-xxx-xxxx
# 改到 (xxx) 或xxx-加xxx-xxxx