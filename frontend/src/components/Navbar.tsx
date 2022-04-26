import React, { useState } from "react";
import { CogIcon, UserIcon, ChartBarIcon } from "@heroicons/react/outline";
import Settings from "./Settings";
import InfoPopup from "./InfoPopup";
import Sidebar from "./Sidebar";
import { Link } from "react-router-dom";
import LoginPopup from "./LoginPopup";

export default function Navbar() {
  const [settingsOpen, setSettingsOpen] = useState<boolean>(false);
  const [loginOpen, setLoginOpen] = useState<boolean>(false);

  return (
    <>
      <Settings settingsOpen={settingsOpen} setSettingsOpen={setSettingsOpen} />
      <LoginPopup loginOpen={loginOpen} setLoginOpen={setLoginOpen} />
      <nav className="navbar">
        <div className="navbar__container--left">
          <Sidebar />
          <InfoPopup />
        </div>

        <button onClick={() => window.location.reload()}>
          <div className="navbar__title">CLAUDLE</div>
        </button>

        <div className="navbar__container--right">
          <Link to="/stats">
            <ChartBarIcon className="navbar__icon" />
          </Link>
          <button onClick={() => setLoginOpen(true)}>
            <UserIcon className="navbar__icon" />
          </button>
          <button onClick={() => setSettingsOpen(true)}>
            <CogIcon className="navbar__icon" />
          </button>
        </div>
      </nav>
    </>
  );
}
