import React, { useContext, useEffect, useState } from "react";
import Footer from "../components/Footer";
import GameBoard from "../components/GameBoard";
import Keyboard from "../components/Keyboard";
import Navbar from "../components/Navbar";
import { SettingsContext } from "../App";

export default function HomePage() {
  const settingsContext = useContext(SettingsContext);
  const [words, setWords] = useState<string[][]>([]);
  const [hints, setHints] = useState<number[][]>([]);
  const [currentWord, setCurrentWord] = useState<string>("");
  const [currentIndex, setCurrentIndex] = useState<number>(0);
  const [keyboardHints, setKeyboardHints] = useState(new Map<string, number>());

  function addLetter(key: string) {
    var newCurrentWord = currentWord;
    var newCurrentIndex = currentIndex;
    if (key === "Del") {
      if (currentWord.length > 0) {
        newCurrentWord = currentWord.slice(0, -1);
      }
    } else if (key === "Enter") {
      // TODO : validate word
      if (currentWord.length === settingsContext.size) {
        newCurrentWord = "";
        setCurrentIndex(currentIndex + 1);
        newCurrentIndex += 1;
      } else {
        return;
      }
    } else if (
      currentWord.length < settingsContext.size &&
      "qwertyuiopasdfghjklzxcvbnm".includes(key)
    ) {
      newCurrentWord = currentWord + key;
    }
    setCurrentWord(newCurrentWord);
    var _words = words;
    var currWordArray = newCurrentWord.split("");
    while (currWordArray.length < settingsContext.size) {
      currWordArray.push("");
    }
    _words[newCurrentIndex] = currWordArray;
    setWords(_words);
  }

  useEffect(() => {
    // Initialize the letters and hints
    const letterRow = [];
    const hintRow = [];
    for (let i = 0; i < settingsContext.size; i++) {
      letterRow.push("");
      hintRow.push(0);
    }
    const _letters = [];
    const _hints = [];
    for (let i = 0; i < settingsContext.tries; i++) {
      _letters.push(letterRow);
      _hints.push(hintRow.slice());
    }
    setWords(_letters);
    setHints(_hints);
  }, [settingsContext.size, settingsContext.tries]);

  return (
    <>
      <Navbar />
      <GameBoard
        size={settingsContext.size}
        tries={settingsContext.tries}
        words={words}
        hints={hints}
      />
      <Keyboard
        layout={settingsContext.layout}
        addLetter={addLetter}
        keyboardHints={keyboardHints}
      />
      <Footer />
    </>
  );
}
