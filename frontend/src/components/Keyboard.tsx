import { useEffect } from "react";
import { BackspaceIcon, ArrowRightIcon } from "@heroicons/react/outline";

interface Props {
  layout: string;
  addLetter(key: string): void;
  keyboardHints: Map<string, number>;
}

export default function Keyboard({ layout, addLetter, keyboardHints }: Props) {
  const qwerty = [
    ["q", "w", "e", "r", "t", "y", "u", "i", "o", "p"],
    ["a", "s", "d", "f", "g", "h", "j", "k", "l"],
    ["Enter", "z", "x", "c", "v", "b", "n", "m", "Del"],
  ];
  const azerty = [
    ["a", "z", "e", "r", "t", "y", "u", "i", "o", "p"],
    ["q", "s", "d", "f", "g", "h", "j", "k", "l", "m"],
    ["Enter", "w", "x", "c", "v", "b", "n", "Del"],
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
    } else if ("qwertyuiopasdfghjklzxcvbnm".includes(keyName.toLowerCase())) {
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
        {keyboards.get(layout)?.map((row, index) => {
          return (
            <div className="keyboard__row" key={`row_${index}`}>
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
                  onClick={() => addLetter(key)}
                  key={key}
                >
                  {key === "Enter" ? (
                    <ArrowRightIcon className="keyboard__icon" />
                  ) : key === "Del" ? (
                    <BackspaceIcon className="keyboard__icon" />
                  ) : (
                    key.toUpperCase()
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
