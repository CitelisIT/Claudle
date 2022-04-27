import React from "react";
import GameBoardRow from "./GameBoardRow";

interface Props {
  words: string[][];
  hints: number[][];
}

export default function GameBoard({ words, hints }: Props) {
  return (
    <section className="game-wrapper">
      <div className="game-board">
        {words.map((row, index) => (
          <GameBoardRow
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
