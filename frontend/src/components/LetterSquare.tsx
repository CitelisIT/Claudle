import React from "react";

interface Props {
  letter: string;
  hint: number;
}

export default function LetterSquare({ letter, hint }: Props) {
  var className = "";
  switch (hint) {
    case 0: {
      className = "letter-square--out";
      break;
    }
    case 1: {
      className = "letter-square--misplaced";
      break;
    }
    case 2: {
      className = "letter-square--correct";
      break;
    }
    default: {
      className = "letter-square--default";
    }
  }
  return (
    <div className={className}>
      <span className="letter-square__letter">{letter.toUpperCase()}</span>
    </div>
  );
}
