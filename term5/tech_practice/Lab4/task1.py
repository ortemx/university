import json

commands = {}

with open("standings_all_seasons.json", "r", encoding='utf-8') as jsonfile:
    data = json.load(jsonfile)
    for d in data:
        for standing in d["league"]["standings"][0]:
            command = standing["team"]["name"]
            if command not in commands:
                commands[command] = standing["points"]
            else:
                commands[command] += standing["points"]

commands = {k: v for k, v in sorted(commands.items(), key=lambda item: item[1], reverse=True)}

top_commands = list(commands)[:10:]

print(top_commands)
