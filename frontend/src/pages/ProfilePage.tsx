import { useState, useEffect } from "react";
import { LogoutIcon, TrashIcon } from "@heroicons/react/outline";

import axios from "axios";
import Footer from "../components/Footer";
import Graph from "../components/Graph";
import Navbar from "../components/Navbar";
import Stats from "../components/Stats";
import { getCookie } from "../utils/utils";
import { useNavigate } from "react-router-dom";

export default function ProfilePage() {
  const navigate = useNavigate();
  const [stats, setStats] = useState({
    user_id: 0,
    username: "",
    nbGamesWon: 0,
    percGamesWon: 0,
    currentStreak: 0,
    bestStreak: 0,
    winsByTries: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
  });

  function logout() {
    axios
      .post(
        "/api/logout",
        {},
        {
          withCredentials: true,
          headers: {
            "X-CSRF-Token": getCookie("csrf_access_token")!,
          },
        }
      )
      .then((response) => {
        if (response.status === 200 && response.data.logout === "ok") {
          sessionStorage.removeItem("loggedin");
          navigate("/");
        }
      });
  }

  function delUser() {
    axios
      .delete(
        "/api/delUser",

        {
          withCredentials: true,
          headers: {
            "X-CSRF-Token": getCookie("csrf_access_token")!,
          },
        }
      )
      .then((response) => {
        if (response.status === 200 && response.data.logout === "ok") {
          sessionStorage.removeItem("loggedin");
          navigate("/");
        }
      });
  }
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
        <button type="submit" className="button--red" onClick={() => logout()}>
          <LogoutIcon className="button__icon" />
          Se déconnecter
        </button>
      </div>
      <div className="flex justify-center w-full gap-4 p-6 md:gap-12 md:p-16">
        <button type="submit" className="button--red" onClick={() => delUser()}>
          <TrashIcon className="button__icon" />
          SUPPRIMER LE COMPTE
        </button>
      </div>
      <Footer />
    </>
  );
}
