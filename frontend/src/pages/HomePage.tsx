import React from "react";
import Footer from "../components/Footer";
import GameBoard from "../components/GameBoard";
import Keyboard from "../components/Keyboard";
import Navbar from "../components/Navbar";

export default function HomePage() {
  const layout = "qwerty";

  return (
    <>
      <Navbar />
      <GameBoard size={5} tries={6} />
      <Keyboard layout={layout} />
      <Footer />
    </>
  );
}
