import React, { useEffect } from "react";
import { BackspaceIcon, ArrowRightIcon } from "@heroicons/react/outline";

interface Props {
  layout: string;
  addLetter(key: string): void;
  keyboardHints: Map<string, number>;
}

export default function Keyboard({ layout, addLetter, keyboardHints }: Props) {
  const qwerty = [
    ["Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P"],
    ["A", "S", "D", "F", "G", "H", "J", "K", "L"],
    ["Enter", "Z", "X", "C", "V", "B", "N", "M", "Del"],
  ];
  const azerty = [
    ["A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P"],
    ["Q", "S", "D", "F", "G", "H", "J", "K", "L", "M"],
    ["Entrée", "W", "X", "C", "V", "B", "N", "Suppr"],
  ];
  const keyboards = new Map([
    ["azerty", azerty],
    ["qwerty", qwerty],
  ]);

  //   Get key pressed by user
  function handleKeyPress(event: KeyboardEvent) {
    const keyName = event.key;
    if (keyName === "Backspace") {
      addLetter("Del");
    }
    if (keyName === "Enter") {
      addLetter("Enter");
    } else if ("qwertyuiopasdfghjklzxcvbnm".includes(keyName)) {
      addLetter(keyName);
    }
  }

  useEffect(() => {
    document.addEventListener("keydown", handleKeyPress);
    return () => document.removeEventListener("keydown", handleKeyPress);
  });

  return (
    <section className="keyboard-wrapper">
      <div className="keyboard">
        {keyboards.get(layout)?.map((row) => {
          return (
            <div className="keyboard__row">
              {row.map((key) => (
                <button
                  className={
                    keyboardHints.get(key) === 1
                      ? "keyboard__letter--misplaced"
                      : keyboardHints.get(key) === 2
                      ? "keyboard__letter--correct"
                      : keyboardHints.get(key) === 0
                      ? "keyboard__letter--out"
                      : "keyboard__letter--default"
                  }
                  onClick={() => addLetter(key.toLowerCase())}
                >
                  {key === "Enter" || key === "Entrée" ? (
                    <ArrowRightIcon className="keyboard__icon" />
                  ) : key === "Del" || key === "Suppr" ? (
                    <BackspaceIcon className="keyboard__icon" />
                  ) : (
                    key
                  )}
                </button>
              ))}
            </div>
          );
        })}
      </div>
    </section>
  );
}
