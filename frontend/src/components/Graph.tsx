import { useState, useEffect } from "react";
import axios from "axios";

export default function Graph() {
  const URL = "http://127.0.0.1:5000/api/stats";
  const [stats, setStats] = useState({
    winsByTries: [0, 0, 0, 0, 2, 0, 0, 0, 0],
  });

  useEffect(() => {
    axios.get(URL).then((response) => {
      setStats(response.data);
    });
  }, []);
  if (!stats) return null;
  return (
    <div className="flex flex-col items-center justify-center">
      <div className="flex flex-col items-start justify-center gap-4 my-8 a -lg lg:text-xl">
        <div className="flex flex-row items-center justify-start gap-2">
          <span>1</span>
          <div className="py-1 pl-20 pr-2 text-right bg-green-600 rounded-sm">
            {stats.winsByTries[0]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>2</span>
          <div className="py-1 pl-8 pr-2 text-right bg-green-600 rounded-sm ">
            {stats.winsByTries[1]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>3</span>
          <div className="py-1 pl-64 pr-2 text-right bg-green-600 rounded-sm">
            {stats.winsByTries[2]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>4</span>
          <div className="py-1 pl-64 pr-2 text-right bg-green-600 rounded-sm">
            {stats.winsByTries[3]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>5</span>
          <div className="py-1 pl-64 pr-2 text-right bg-green-600 rounded-sm">
            {stats.winsByTries[4]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>6</span>
          <div className="py-1 pl-64 pr-2 text-right bg-green-600 rounded-sm">
            {stats.winsByTries[5]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>7</span>
          <div className="py-1 pl-64 pr-2 text-right bg-green-600 rounded-sm">
            {stats.winsByTries[6]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>8</span>
          <div className="py-1 pl-64 pr-2 text-right bg-green-600 rounded-sm">
            {stats.winsByTries[7]}
          </div>
        </div>
        <div className="flex flex-row items-center justify-start gap-2">
          <span>9</span>
          <div className="py-1 pl-64 pr-2 text-right bg-green-600 rounded-sm">
            {stats.winsByTries[8]}
          </div>
        </div>
      </div>
    </div>
  );
}
