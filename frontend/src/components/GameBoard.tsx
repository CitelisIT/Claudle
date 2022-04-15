import React, { useEffect, useState } from "react";
import GameRow from "./GameBoardRow";

interface Props {
  size: number;
  tries: number;
  words: string[][];
  hints: number[][];
}

export default function GameBoard({ size, tries, words, hints }: Props) {
  return (
    <section className="game-wrapper">
      <div className="game-board">
        {words.map((row, index) => (
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
