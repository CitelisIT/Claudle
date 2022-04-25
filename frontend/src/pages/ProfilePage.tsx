import { useState, useEffect } from "react";
import { LogoutIcon } from "@heroicons/react/outline";
import axios from "axios";
import Footer from "../components/Footer";
import Graph from "../components/Graph";
import Navbar from "../components/Navbar";
import Stats from "../components/Stats";

export default function ProfilePage() {
  const [stats, setStats] = useState({
    username: "Jean",
    user_id: 0,
  });
  const URL = "http://127.0.0.1:5000/api/profile";

  useEffect(() => {
    axios.get(URL).then((response) => {
      setStats(response.data);
    });
  }, []);
  if (!stats) return null;
  return (
    <>
      <Navbar />
      <div className="flex flex-col items-center justify-center gap-6 mx-auto my-16 text-gray-200 md:items-start w-fit">
        <span className="flex items-center justify-center w-full text-xl font-semibold md:text-2xl lg:text-4xl">
          <h1 className="text-center">Bonjour {stats.username}</h1>
        </span>
        <h2 className="mt-4 text-lg md:mt-16 md:mb-6 md:text-xl lg:text-2xl">
          Voici tes performances :
        </h2>
        <Stats user_id={stats.user_id} />
        <Graph />
      </div>
      <div className="flex justify-center w-full gap-4 p-6 md:gap-12 md:p-16">
        <button
                type="submit"
                className="flex items-center justify-center w-max p-2 text-sm text-red-500 border border-red-500 rounded-lg md:text-lg lg:text-xl"
              >
                <LogoutIcon className="w-10 h-10 lg:h-12 lg:w-12" />
                Se déconnecter
              </button>
        </div>
      <Footer />
    </>
  );
}
