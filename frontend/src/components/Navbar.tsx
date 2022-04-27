import React, { useState } from "react";
import { CogIcon, UserIcon, ChartBarIcon } from "@heroicons/react/outline";
import Settings from "./Settings";
import InfoPopup from "./InfoPopup";
import Sidebar from "./Sidebar";
import { Link } from "react-router-dom";
import LoginPopup from "./LoginPopup";

interface Props {
  setPopupOpen: React.Dispatch<React.SetStateAction<boolean>>;
}

export default function Navbar({ setPopupOpen }: Props) {
  const [settingsOpen, setSettingsOpen] = useState<boolean>(false);
  const [loginOpen, setLoginOpen] = useState<boolean>(false);

  return (
    <>
      <Settings
        settingsOpen={settingsOpen}
        setSettingsOpen={setSettingsOpen}
        setPopupOpen={setPopupOpen}
      />
      <LoginPopup
        loginOpen={loginOpen}
        setLoginOpen={setLoginOpen}
        setPopupOpen={setPopupOpen}
      />
      <nav className="navbar">
        <div className="navbar__container--left">
          <Sidebar />
          <InfoPopup />
        </div>

        <Link to="/" className="navbar__title" reloadDocument>
          CLAUDLE
        </Link>

        <div className="navbar__container--right">
          <Link to="/stats">
            <ChartBarIcon className="navbar__icon" />
          </Link>
          <button
            onClick={() => {
              setPopupOpen(true);
              setLoginOpen(true);
            }}
          >
            <UserIcon className="navbar__icon" />
          </button>
          <button
            onClick={() => {
              setPopupOpen(true);
              setSettingsOpen(true);
            }}
          >
            <CogIcon className="navbar__icon" />
          </button>
        </div>
      </nav>
    </>
  );
}
