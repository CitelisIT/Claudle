import React, { useState, useEffect } from "react";
import axios from "axios";

interface Props {
  user_id: number;
}

export default function Stats(user_id: Props) {
  const [stats, setStats] = useState({
    user_id: 0,
    username: "",
    nbGamesWon: 0,
    percGamesWon: 0,
    currentStreak: 0,
    bestStreak: 0,
    winsByTries: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
  });

  useEffect(() => {
    const token = sessionStorage.getItem("token");
    axios
      .get("/api/profile", {
        headers: {
          Authorization: `Bearer ${token}`,
        },
      })
      .then((response) => {
        setStats(response.data);
      });
  }, []);
  if (!stats) return null;
  return (
    <section id="stats" className="flex items-center justify-center">
      <div className="flex flex-col items-center justify-center gap-4 text-gray-200 text-md md:text-lg lg:text-xl md:items-start">
        <div className="flex flex-col items-center justify-center md:flex-row">
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">{stats.nbGamesWon}</span>
            <span className="font-light">Parties Gagnées</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">
              {stats.percGamesWon}%
            </span>
            <span className="font-light"> Pourcentage De Parties Gagnées</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">
              {stats.currentStreak}
            </span>
            <span className="font-light">Série actuelle</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">{stats.bestStreak}</span>
            <span className="font-light">Meilleure Série</span>
          </div>
        </div>
      </div>
    </section>
  );
}
