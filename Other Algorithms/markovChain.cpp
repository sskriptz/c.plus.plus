#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <random>
using namespace std;

string generateText(const string &text, int generatedWords) {
    // split text into words
    vector<string> words;
    istringstream iss(text);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    // make the Markov Chain
    map<string, map<string, int>> chain;
    for (int i = 0; i < words.size() - 1; i++) {
        chain[words[i]][words[i + 1]]++;
    }

    // Choose a random starting word
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, words.size() - 2);
    string currentWord = words[dist(gen)];

    string output = currentWord + " ";

    // Generate words
    for (int n = 1; n < generatedWords; n++) {
        auto &innerMap = chain[currentWord];

        // if there are no next words, pick a random word from the text
        if (innerMap.empty()) {
            currentWord = words[dist(gen)];
            output += currentWord + " ";
            continue;
        }

        // Extract next words and their frequencies
        vector<string> nextWords;
        vector<int> nextFrequencies;
        int total = 0;
        for (auto &p : innerMap) {
            nextWords.push_back(p.first);
            nextFrequencies.push_back(p.second);
            total += p.second;
        }

        // Pick weighted random next word
        uniform_int_distribution<> dist2(1, total);
        int r = dist2(gen);

        int cumulative = 0;
        string chosenWord;
        for (int i = 0; i < nextWords.size(); i++) {
            cumulative += nextFrequencies[i];
            if (r <= cumulative) {
                chosenWord = nextWords[i];
                break;
            }
        }

        // add the chosen word and update currentWord
        output += chosenWord + " ";
        currentWord = chosenWord;
    }

    return output;
}

int main() {
    string text =
    "Long ago, in a quiet valley surrounded by towering mountains, there lived a curious traveler. "
    "Every morning he wandered along winding paths, observing the shifting colors of the sky. "
    "The villagers often saw him jotting notes in a battered journal, recording every strange or beautiful thing he encountered. "
    "Some claimed he sought a forgotten treasure hidden deep beneath the old forest. "
    "Others believed he searched for a rare creature that appeared only under the pale light of the moon. "
    "Despite the rumors, the traveler rarely spoke about his purpose. "
    "He simply smiled, shared a warm greeting, and continued on his way. "
    "One evening, as the sun dipped behind the cliffs, a cold wind swept through the valley. "
    "The traveler paused, sensing a change in the air. "
    "Something ancient seemed to awaken in the forest, as if the shadows themselves were shifting. "
    "He closed his journal, tightened his cloak, and stepped forward without hesitation. "
    "The villagers watched from afar, unsure whether they should follow or stay behind. "
    "But the traveler did not look back. "
    "His footsteps vanished into the darkness, leaving only questions behind.";

    string result = generateText(text, 50);
    cout << result << endl;

    return 0;
}
