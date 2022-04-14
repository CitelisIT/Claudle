import React from "react";
import Footer from "../components/Footer";
import Graph from "../components/Graph";
import Navbar from "../components/Navbar";
import Stats from "../components/Stats";

export default function StatsPage() {
  return (
    <>
      <Navbar />
      <div className="flex flex-col items-center justify-center gap-6 mx-auto my-16 text-gray-200 md:items-start w-fit max-w-[83%]">
        <span className="flex items-center justify-center w-full text-xl font-semibold md:text-2xl lg:text-4xl">
          <h1 className="text-center">Les performances de tous les joueurs</h1>
        </span>
        <h2 className="mt-4 text-lg md:mt-16 md:mb-6 md:text-xl lg:text-2xl">
          Statistiques :
        </h2>
        <Stats />
        <Graph />
      </div>
      <Footer />
    </>
  );
}
