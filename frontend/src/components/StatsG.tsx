import React, { useState, useEffect } from "react";
import axios from "axios";
import { number } from "yup";

interface Props {
  nbGamesPlayed: number;
  percGamesWon: number;
  bestUser: string;
  bestStreak: number;
}

export default function StatsG({
  nbGamesPlayed,
  percGamesWon,
  bestUser,
  bestStreak,
}: Props) {
  return (
    <section id="stats" className="flex items-center justify-center">
      <div className="flex flex-col items-center justify-center gap-4 text-gray-200 text-md md:text-lg lg:text-xl md:items-start">
        <div className="flex flex-col items-center justify-center md:flex-row">
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">{nbGamesPlayed}</span>
            <span className="font-light">Parties Jouées</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">{percGamesWon}%</span>
            <span className="font-light"> Pourcentage De Parties Gagnées</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">{bestUser}</span>
            <span className="font-light">Meilleur joueur</span>
          </div>
          <div className="flex flex-col items-center justify-center gap-2 p-4">
            <span className="text-3xl font-semibold">{bestStreak}</span>
            <span className="font-light">Meilleure Série</span>
          </div>
        </div>
      </div>
    </section>
  );
}
