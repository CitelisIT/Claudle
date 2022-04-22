import React, { useState, useEffect } from "react";
import axios from "axios";

export default function StatsG() {
  const [stats, setStats] = useState({
    nbGamesPlayed: 0,
    percGamesWon: 0,
    bestStreak: 0,
    bestUser: "",
    winsByTries: [0, 0, 0, 0, 2, 0, 0, 0, 0],
  });

  useEffect(() => {
    axios.get("/api/stats").then((response) => {
      setStats(response.data);
    });
  }, []);
  if (!stats) return null;
  return (
    <section id="stats" className="flex items-center justify-center">
      <div className="flex flex-col items-center justify-center gap-4 text-gray-200 text-md md:text-lg lg:text-xl md:items-start">
        <div className="flex flex-col items-center justify-center md:flex-row">
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">
              {stats.nbGamesPlayed}
            </span>
            <span className="font-light">Parties Jouées</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">
              {stats.percGamesWon}%
            </span>
            <span className="font-light"> Pourcentage De Parties Gagnées</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">{stats.bestUser}</span>
            <span className="font-light">Meilleur joueur</span>
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
