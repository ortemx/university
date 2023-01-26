import datetime

start = datetime.timedelta(hours=9)
finish = datetime.timedelta(hours=15, minutes=45)
print(f'прошло {(finish - start).seconds} секунд')
