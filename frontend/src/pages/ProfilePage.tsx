import { useState, useEffect } from "react";
import { LogoutIcon } from "@heroicons/react/outline";
import axios from "axios";
import Footer from "../components/Footer";
import Graph from "../components/Graph";
import Navbar from "../components/Navbar";
import Stats from "../components/Stats";
import { getCookie } from "../utils/utils";

export default function ProfilePage() {
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
    axios
      .get("/api/profile", {
        withCredentials: true,
        headers: {
          "X-CSRF-Token": getCookie("csrftoken")!,
        },
      })
      .then((response) => {
        setStats(response.data);
      });
  }, []);
  if (!stats) return null;
  return (
    <>
      <Navbar setPopupOpen={() => {}} />
      <div className="flex flex-col items-center justify-center gap-6 mx-auto my-16 text-gray-200 md:items-start w-fit">
        <span className="flex items-center justify-center w-full text-xl font-semibold md:text-2xl lg:text-4xl">
          <h1 className="text-center">Bonjour {stats.username}</h1>
        </span>
        <h2 className="mt-4 text-lg md:mt-16 md:mb-6 md:text-xl lg:text-2xl">
          Voici tes performances :
        </h2>
        <Stats
          nbGamesWon={stats.nbGamesWon}
          percGamesWon={stats.percGamesWon}
          currentStreak={stats.currentStreak}
          bestStreak={stats.bestStreak}
        />
        <Graph winsByTries={stats.winsByTries} />
      </div>
      <div className="flex justify-center w-full gap-4 p-6 md:gap-12 md:p-16">
        <button type="submit" className="button--red">
          <LogoutIcon className="button__icon" />
          Se déconnecter
        </button>
      </div>
      <Footer />
    </>
  );
}
