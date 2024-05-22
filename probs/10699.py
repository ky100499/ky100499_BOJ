from datetime import datetime, timezone, timedelta

print(datetime.now().astimezone(timezone(timedelta(hours=9))).strftime('%Y-%m-%d'))
