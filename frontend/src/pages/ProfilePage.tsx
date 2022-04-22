import { useState, useEffect } from "react";
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
      <Footer />
    </>
  );
}
