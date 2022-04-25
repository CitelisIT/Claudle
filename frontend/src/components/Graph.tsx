import { useState, useEffect } from "react";
import axios from "axios";

export default function Graph() {
  const URL = "http://127.0.0.1:5000/api/stats";
  const [stats, setStats] = useState({
    winsByTries: [0, 0, 0, 0, 0, 0, 0, 0, 0],
  });

  useEffect(() => {
    axios.get(URL).then((response) => {
      setStats(response.data);
    });
  }, []);
  if (!stats) return null;
  const max = stats.winsByTries.reduce((op, item) => op = op > item ? op : item, 0);
  const normOne = Math.floor(stats.winsByTries[0] / max * 100);
  const normTwo = Math.floor(stats.winsByTries[1] / max * 100);
  const normThree = Math.floor(stats.winsByTries[2] / max * 100);
  const normFour = Math.floor(stats.winsByTries[3] / max * 100);
  const normFive = Math.floor(stats.winsByTries[4] / max * 100);
  const normSix = Math.floor(stats.winsByTries[5] / max * 100);
  const normSeven = Math.floor(stats.winsByTries[6] / max * 100);
  const normEight = Math.floor(stats.winsByTries[7] / max * 100);
  const normNine = Math.floor(stats.winsByTries[8] / max * 100);
  return (
    <div className="flex flex-col items-center justify-center w-full">
      <div className="flex flex-col items-start justify-center gap-4 my-8 a -lg lg:text-xl w-full">
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>1</span>
          <div className={`py-1 w-[${normOne}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[0]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>2</span>
          <div className={`py-1 w-[${normTwo}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[1]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>3</span>
          <div className={`py-1 w-[${normThree}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[2]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>4</span>
          <div className={`py-1 w-[${normFour}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[3]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>5</span>
          <div className={`py-1 w-[${normFive}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[4]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>6</span>
          <div className={`py-1 w-[${normSix}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[5]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>7</span>
          <div className={`py-1 w-[${normSeven}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[6]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>8</span>
          <div className={`py-1 w-[${normEight}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[7]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2 w-full">
          <span>9</span>
          <div className={`py-1 w-[${normNine}%] min-w-fit text-right bg-green-600 rounded-sm text-end px-2`}>
            {stats.winsByTries[8]}
          </div>
        </div>
      </div>
    </div>
  );
}
