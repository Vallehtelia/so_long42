#!/bin/bash

GREEN='\033[0;92m'
BLUE='\033[0;94m'
RED='\033[0;91m'
NC='\033[0m'

RESULTS_FILE="results.txt"
TEMP_RESULTS="temp_results.txt"

echo "Cleaning previous build..."
make fclean

echo "Building the project..."
make
make clean

> "$RESULTS_FILE"
> "$TEMP_RESULTS"

./so_long ./maps/empty.ber >> "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] Empty maps${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] Empty maps${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/map19-bad_collect.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] Bad collect${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] Bad collect${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/map19-no_exit.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] Bad exit${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] Bad exit${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/no_collectible.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] No collectables${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] No collectables{NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/no_exit.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] No exit2${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] No exit 2${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/no_player.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] No player${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] No player${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/no_rectangle.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] Bad shape${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] Bad shape${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/not_walled.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] Bad walls${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] Bad walls${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/two_player.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] Two player${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] Two player${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/wrong_name.be > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] Bad name${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] Bad name${NC}" >> "$RESULTS_FILE"
fi

./so_long ./maps/zero_wall.ber > "$TEMP_RESULTS"
if grep -q "Error:" "$TEMP_RESULTS"; then
	echo -e "${GREEN}[OK] No walls${NC}" >> "$RESULTS_FILE"
else
    echo -e "${RED}[KO] No walls${NC}" >> "$RESULTS_FILE"
fi

echo -e "${BLUE}--------------SUMMARY OF RESULTS--------------${NC}"
cat "$RESULTS_FILE"
rm "$TEMP_RESULTS"
rm "$RESULTS_FILE"
