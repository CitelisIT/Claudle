import { useEffect, useState } from "react";
import axios from "axios";
import Footer from "../components/Footer";
import Graph from "../components/Graph";
import Navbar from "../components/Navbar";
import StatsG from "../components/StatsG";

export default function StatsPage() {
  const [stats, setStats] = useState({
    nbGamesPlayed: 0,
    percGamesWon: 0,
    bestStreak: 0,
    bestUser: "",
    winsByTries: [0, 0, 0, 0, 0, 0, 0, 0, 0],
  });

  useEffect(() => {
    axios.get("/api/stats").then((response) => {
      setStats(response.data);
    });
  }, []);
  if (!stats) return null;
  return (
    <>
      <Navbar setPopupOpen={() => {}} />
      <div className="flex flex-col items-center justify-center gap-6 mx-auto my-16 text-gray-200 md:items-start w-fit max-w-[83%]">
        <span className="flex items-center justify-center w-full text-xl font-semibold md:text-2xl lg:text-4xl">
          <h1 className="text-center">Les performances de tous les joueurs</h1>
        </span>
        <h2 className="mt-4 text-lg md:mt-16 md:mb-6 md:text-xl lg:text-2xl">
          Statistiques :
        </h2>
        <StatsG
          nbGamesPlayed={stats.nbGamesPlayed}
          percGamesWon={stats.percGamesWon}
          bestUser={stats.bestUser}
          bestStreak={stats.bestStreak}
        />
        <Graph winsByTries={stats.winsByTries} />
      </div>
      <Footer />
    </>
  );
}
