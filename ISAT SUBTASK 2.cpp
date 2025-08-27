#include <iostream>
void actionEncodeInteractive() {
cout << "Enter English text: ";
string line; getline(cin, line);
string morse = encodeToMorse(trim(line));
cout << "\nMorse: " << morse << "\n";
}


void actionDecodeInteractive() {
cout << "Enter Morse (use spaces between letters and '/' between words): ";
string line; getline(cin, line);
string eng = decodeFromMorse(trim(line));
cout << "\nEnglish: " << eng << "\n";
}


void actionBatchEncode() {
cout << "Input text file path: ";
string in; getline(cin, in);
cout << "Output file path (will be overwritten): ";
string out; getline(cin, out);


string content = readWholeFile(in);
if (content.empty()) {
cout << "Could not read input file or file is empty.\n";
return;
}
string morse = encodeToMorse(content);
if (writeTextFile(out, morse)) cout << "Saved Morse to '" << out << "'\n";
else cout << "Failed to write output file.\n";
}


void actionBatchDecode() {
cout << "Input Morse file path: ";
string in; getline(cin, in);
cout << "Output file path (will be overwritten): ";
string out; getline(cin, out);


string content = readWholeFile(in);
if (content.empty()) {
cout << "Could not read input file or file is empty.\n";
return;
}
string eng = decodeFromMorse(content);
if (writeTextFile(out, eng)) cout << "Saved English to '" << out << "'\n";
else cout << "Failed to write output file.\n";
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);


while (true) {
printBanner();
cout << "Choose an option: ";
string choice; getline(cin, choice);
if (choice == "0") { cout << "Goodbye!\n"; break; }
else if (choice == "1") actionEncodeInteractive();
else if (choice == "2") actionDecodeInteractive();
else if (choice == "3") actionBatchEncode();
else if (choice == "4") actionBatchDecode();
else if (choice == "5") printHelp();
else cout << "Unknown option. Try again.\n";
cout << "\nPress ENTER to continue..."; string pause; getline(cin, pause);
}
return 0;
}
