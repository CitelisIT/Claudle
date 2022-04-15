import React, { useEffect, useState } from "react";
import GameRow from "./GameBoardRow";

interface Props {
  size: number;
  tries: number;
}

export default function GameBoard({ size, tries }: Props) {
  const [letters, setLetters] = useState<string[][]>([]);
  const [hints, setHints] = useState<number[][]>([]);
  useEffect(() => {
    // Initialize the letters and hints
    const letterRow = [];
    const hintRow = [];
    for (let i = 0; i < size; i++) {
      letterRow.push("");
      hintRow.push(0);
    }
    const _letters = [];
    const _hints = [];
    for (let i = 0; i < tries; i++) {
      _letters.push(letterRow);
      _hints.push(hintRow.slice());
    }
    setLetters(_letters);
    setHints(_hints);
  }, [size, tries]);
  return (
    <section className="game-wrapper">
      <span>{letters}</span>
      <div className="game-board">
        {letters.map((row, index) => (
          <GameRow
            size={row.length}
            letters={row}
            hints={hints[index]}
            key={index}
          />
        ))}
      </div>
    </section>
  );
}
