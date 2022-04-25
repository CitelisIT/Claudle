import React from "react";
import LetterSquare from "./LetterSquare";

interface Props {
  size: number;
  letters: string[];
  hints: number[];
}

export default function GameBoardRow({ size, letters, hints }: Props) {
  return (
    <div className="game-board__row">
      {letters.map((letter, index) => (
        <LetterSquare letter={letter} hint={hints[index]} key={index} />
      ))}
    </div>
  );
}
