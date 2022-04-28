interface Props {
  winsByTries: number[];
}

export default function Graph({ winsByTries }: Props) {
  const max = winsByTries.reduce(
    (op: any, item: any) => (op = op > item ? op : item),
    0
  );
  const normOne =
    (max !== 0 ? Math.floor((winsByTries[0] / max) * 100) : 0) + "%";
  const normTwo =
    (max !== 0 ? Math.floor((winsByTries[1] / max) * 100) : 0) + "%";
  const normThree =
    (max !== 0 ? Math.floor((winsByTries[2] / max) * 100) : 0) + "%";
  const normFour =
    (max !== 0 ? Math.floor((winsByTries[3] / max) * 100) : 0) + "%";
  const normFive =
    (max !== 0 ? Math.floor((winsByTries[4] / max) * 100) : 0) + "%";
  const normSix =
    (max !== 0 ? Math.floor((winsByTries[5] / max) * 100) : 0) + "%";
  const normSeven =
    (max !== 0 ? Math.floor((winsByTries[6] / max) * 100) : 0) + "%";
  const normEight =
    (max !== 0 ? Math.floor((winsByTries[7] / max) * 100) : 0) + "%";
  const normNine =
    (max !== 0 ? Math.floor((winsByTries[8] / max) * 100) : 0) + "%";
  const normTen =
    (max !== 0 ? Math.floor((winsByTries[9] / max) * 100) : 0) + "%";
  return (
    <div className="flex flex-col items-center justify-center w-full">
      <div className="flex flex-col items-start justify-center w-full gap-4 my-8 a -lg lg:text-xl">
        <div className="flex flex-row items-center justify-start w-full gap-2">
          <span className="w-8 text-right">1</span>
          <div
            style={{ width: normOne }}
            className={`py-1 min-w-fit text-right bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[0]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">2</span>
          <div
            style={{ width: normTwo }}
            className={`py-1 min-w-fit bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[1]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">3</span>
          <div
            style={{ width: normThree }}
            className={`py-1 min-w-fit bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[2]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">4</span>
          <div
            style={{ width: normFour }}
            className={`py-1 min-w-fit bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[3]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">5</span>
          <div
            style={{ width: normFive }}
            className={`py-1 min-w-fit bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[4]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">6</span>
          <div
            style={{ width: normSix }}
            className={`py-1 min-w-fit bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[5]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">7</span>
          <div
            style={{ width: normSeven }}
            className={`py-1 min-w-fit bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[6]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">8</span>
          <div
            style={{ width: normEight }}
            className={`py-1 min-w-fit text-right bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[7]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">9</span>
          <div
            style={{ width: normNine }}
            className={`py-1 min-w-fit bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[8]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start w-full gap-2 text-right">
          <span className="w-8 text-right">10</span>
          <div
            style={{ width: normTen }}
            className={`py-1 min-w-fit bg-green-600 rounded-sm px-2`}
          >
            {winsByTries[9]}
          </div>
        </div>
      </div>
    </div>
  );
}
