import React, { useContext, useEffect, useState } from "react";
import Footer from "../components/Footer";
import GameBoard from "../components/GameBoard";
import Keyboard from "../components/Keyboard";
import Navbar from "../components/Navbar";
import { SettingsContext } from "../App";
import axios from "axios";

export default function HomePage() {
  const settingsContext = useContext(SettingsContext);
  const [target, setTarget] = useState<string>("");
  const [words, setWords] = useState<string[][]>([]);
  const [hints, setHints] = useState<number[][]>([]);
  const [currentWord, setCurrentWord] = useState<string>("");
  const [currentIndex, setCurrentIndex] = useState<number>(0);
  const [keyboardHints, setKeyboardHints] = useState(new Map<string, number>());

  function addLetter(key: string) {
    var _words = words;
    var currWordArray: string[];
    if (key === "Del") {
      if (currentWord.length > 0) {
        setCurrentWord(currentWord.slice(0, -1));
        currWordArray = currentWord.slice(0, -1).split("");
        while (currWordArray.length < settingsContext.size) {
          currWordArray.push("");
        }
        _words[currentIndex] = currWordArray;
        setWords(_words);
      }
    } else if (key === "Enter") {
      if (currentWord.length === settingsContext.size) {
        axios
          .get("/api/validate", {
            params: {
              word: currentWord,
              language: settingsContext.lang,
              target: target,
            },
            validateStatus: (status) => {
              return status < 500;
            },
          })
          .then((res) => {
            var _hints = hints;
            const wordHints = res.data.hint;
            _hints[currentIndex] = wordHints;
            setHints(_hints);
            const letterArray = currentWord.split("");
            var _keyboardHints = keyboardHints;
            for (var i = 0, len = letterArray.length; i < len; i++) {
              _keyboardHints.set(letterArray[i], wordHints[i]);
            }
            setKeyboardHints(_keyboardHints);
            setCurrentWord("");
            setCurrentIndex(currentIndex + 1);
          })
          .catch((error) => {
            console.log(error);
          });
      } else {
        return;
      }
    } else if (
      currentWord.length < settingsContext.size &&
      "qwertyuiopasdfghjklzxcvbnm".includes(key)
    ) {
      setCurrentWord(currentWord + key);
      currWordArray = (currentWord + key).split("");
      while (currWordArray.length < settingsContext.size) {
        currWordArray.push("");
      }
      _words[currentIndex] = currWordArray;
      setWords(_words);
    }
  }

  useEffect(() => {
    // Get target Word
    axios
      .get("/api/getword", {
        params: {
          language: settingsContext.lang,
          length: settingsContext.size,
        },
      })
      .then((res) => {
        setTarget(res.data.words);
      });
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
      _hints.push(hintRow);
    }
    setWords(_letters);
    setHints(_hints);
  }, [settingsContext.size, settingsContext.tries, settingsContext.lang]);

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
