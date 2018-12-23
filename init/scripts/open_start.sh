osascript -e "tell application \"Google Chrome\"" -e "activate" -e "tell application \"System Events\"" -e "keystroke \"f\" using {control down, command down}" -e "end tell" -e "end tell"
open -a "Google Chrome" https://tomato-timer.com/
# open -a "Google Chrome" https://youtube.com/
open -a "Google Chrome" https://intra.42.fr/
osascript -e "tell application \"Spotify\"" -e "activate" -e "make new window" -e "tell application \"System Events\"" -e "keystroke \"f\" using {control down, command down}" -e "end tell" -e "end tell"
osascript -e "tell application \"Slack\"" -e "activate" -e "make new window" -e "tell application \"System Events\"" -e "keystroke \"f\" using {control down, command down}" -e "end tell" -e "end tell"
